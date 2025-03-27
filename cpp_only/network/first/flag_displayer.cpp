#include <iostream>
#include <vector>
#include <string>

#include "flag_displayer.h"

// RC4 Encryption/Decryption function
void rc4(const std::string& key, const std::string& input, std::string& output) {
    std::vector<int> S(256);
    std::vector<int> K(256);
    
    // Key scheduling algorithm (KSA)
    for (int i = 0; i < 256; i++) {
        S[i] = i;
        K[i] = key[i % key.length()];
    }

    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + K[i]) % 256;
        std::swap(S[i], S[j]);
    }

    // Pseudo-random generation algorithm (PRGA)
    int i = 0, k = 0;
    for (size_t index = 0; index < input.length(); index++) {
        i = (i + 1) % 256;
        k = (k + S[i]) % 256;
        std::swap(S[i], S[k]);
        int t = (S[i] + S[k]) % 256;
        char keystream = S[t];
        
        // XOR with input byte to encrypt/decrypt
        output += input[index] ^ keystream;
    }
}

std::string hex_to_bytes(const std::string& hex) {
    std::string result;
    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byte = hex.substr(i, 2);
        char ch = (char)(int)strtol(byte.c_str(), nullptr, 16);
        result.push_back(ch);
    }
    return result;
}


int binarySearchAtStep(const std::vector<std::string>& vec, int steps) {
    int left = 0;
    int right = vec.size() - 1;
    int mid = -1;

    // Perform binary search for a specific number of steps
    for (int step = 0; step < steps; ++step) {
        mid = left + (right - left) / 2;

        // Output the index of the middle value at each step
        // std::cout << "Step " << step + 1 << ": Mid index = " << mid << " (Value: " << vec[mid] << ")" << std::endl;

        // Simulate choosing the left or right half
        if (vec[mid] < vec[right]) {
            right = mid;  // Narrow the search to the left half
        } else {
            left = mid + 1;  // Narrow the search to the right half
        }
    }

    // Return the index of the mid point at the 'steps' step
    return mid;
}



// Function implementation
void asio_nsense() {
    // std::string encrypted_flag_hex = "c52e0e7af754d51b0b0c602607b2782275082e568029837db2c2ed23b96b0020ba09e6b86853553dadb89f6fe1";
    std::vector<std::string> hexStrings = {
        "4632ef55afe56a58de568747229358ff5fee7a6654245b4ac293bfcc925750231b781f9353301479629e458b85",
        "f56d132419ad897592ddcee78aa0e5c5d98ea5b364592251c1bdd8c5e078ce68c5cc786c07f88dd2a2acde3808",
        "871e773a4791a610931e1651bb29fa65f7e1fe553ce27b00aaf34550f38ac67ef74a84d1e1a4b565a2b0e75c26",
        "904e94afccfd7f89b6b8f10b101950af3f68e44f5cdb2795c727aeda2b6f9cc3692f50cbe971787189bfb6de23",
        "22611c25d53d69e47729b0ffd435e9c885ba3db32356894da2fc258133bace50a91829076d15f2b03d2f8ba6cf",
        "322d27f62764b633544d73e856a1e607c9289d3ccb375f66ecb7dbcf7ae718f0d5fdee72a2f5446c64c9b66958",
        "d1db777799606f6bb0a40ae3664f586bc1dde53a8f37b53066eed76906742d77dfea96f51b46c8ff02454a461b",
        "460b406985805711ea195a1aae283af5bb523ddf7c9faef9459e1369b23efa09dfb9d6bd0e66a77ea5830ae0c8",
        "29cf26e027fa57383f8568ece2e1fd146d0deafccaec5a6bc266f3d9ff9f656ba766be12b690f60c21f016e094",
        "1004fdc3c58eb3dbb37e4f46f5894a192c8ae4d9ec51b4d421018c506469f7ced97cee1ed5219c29ff0a6d2667",
        "cad8971073f3c7fd94cb332857f7764dbe5b4db6eb635460cd47ece9a514cce15dd6dfa0827299b3384f53dd48",
        "22d0c1da9fcec76dde30ef61316c0a38552a2dbe39c162c3da06451dac735ad031f88d8f227ea157532a2d9e7f",
        "766ca6e0c7fd723a3ff1577a86e59b5f1fbdf545e08f390f7933aedeae28730e4b791a23c212e546e90d591e76",
        "bb0e0c70b6d20a7c82553fbb62f5a09b8bc5927e27860619f0832152449253fe831a305c5772634c726953fdb2",
        "086b03bb7330a0f706da811eab6620236ce840a44f8ac2012b1c579e4a3ddfdff65a8f63d190faa8e500f41ffc",
        "ac9e13f65f927588954605de1896cf044c3888750fdc930150a84e333c7cd02b3c5b475de943041d10f93495d4",
        "796f33ee0007fa0ffe0c368fb7468c42826ce567bda6faf0947608d497a6a95cb63005061ffc58acc6c6b6f74a",
        "f6129baf9fe948ca1d24c0c27973ed8286e1ce182be776d3b8be78f64560594c973182720c0693836bf0fcdf9a",
        "7cdfb3445e39bfd105289d644c10527fb1669d480eb5ae4101abe8bcec665f0df6820c92321dd4d14658a5b47d",
        "829e884357589d5d812cb186d82ead507e48dad4c33af7e6878b6a3d76382579efc49a24b5f1bcdb01e409f9e9",
        "75e5c0d54fdf27f81b188d7343bb519d2cc4460f86ac3c35d25332ac332f4e5e62292b583b1e9309a68b56f4d0",
        "0bcf039a281d74bb21275a28cd1fd020a8ba9aa7105938c06af84892444be926f85430c83090e6b0f0f32763a8",
        "eb6239b64fc51731822d0fbacc917092f5579472264c1acce10dbb9dbd8bf7a86cc4617d3ad3ddebb44b4d36cb",
        "521e2441255a134a5a974ab5a23aebe3b5d11b815bddf965f3d294368265ef6b0bba3aaf6c9b01594a48128dc8",
        "35427ab0235fbc0f8adb87231a8211e63005c4b926c04e5a7878facb9f985cea4375bffce77e3da3a3a61beae8",
        "b178d52358f1828dd67984674944a883db374ca140c184e4d1a5d0acf33c0b06c5246b9b1fbb929ceb23abea13",
        "acacd8c95ce715ca3f7acb72ecd55f136c9ae69d265d5473e374c8b3f72675e4f5131f769885d4580d98ec8cf2",
        "6b3c80966d91d935c48713fefe0356669a3251015ef921f19c2f232921c7a260ac718e6c1ecea75ebcd2eb02b4",
        "3ef86e833322cda47e62525211ad2e8ddafb21a8233c87ed0caf19360d1bc58c19c80ec96402c687ee87718ee7",
        "c52e0e7af754d51b0b0c602607b2782275082e568029837db2c2ed23b96b0020ba09e6b86853553dadb89f6fe1",
        "378f6e4391d784efdf6ef8b01b8aef8f04cbc3a01711e1a97e97be545f8366a38755c90154de678b2e83f72a70",
        "904589890242687f1705d04f4d39e07028a8f518a512c437715f0576d4ee874d607f899876ef773058bc0f95e3",
        "987bfdddc49da1885bd1fb7f4a960c9eb0036e0e2de2be9e50ce65f44b95a2e2c959e53065bee8c2da8e14c755",
        "ce6a8dff148848e1af08061f22d50972c05ca93deea730a9c02c963369107ad8a33256f82c9c7971aa038c862b",
        "597151ef005224f4ad98a0053aa813237973071bdd054b0146d15364b51df610e60246d96657c962b507798615",
        "1136eced8f061603d685960cfc38c570fb1fb7751d8337672ad880fbe63e8392765ffcfa98e93cb6780f59898f",
        "a19fd07d91f4318e555499f921457a99c0a8d117f3cffe0c6232b8ce1a4ab09e69e7b55dae3c9286abaa238cdc",
        "c2feacb78093daa1993fdb1d1164832933e492be8b4e04eb19978448ee49a4f8fc2f0be7a9051e03c1d9654dfb",
        "06f336499551a3c06248585e3c99ae93d413ca059fe7b7db3b14ff06df48d4f71f465dd9bcae26c83a45784bf4",
        "0a399f18f8491e0e5bb9e25031df0e560f246bcb44dfaf5e15da9124c4f4337a5513fac3ba63a683fc5508769e",
        "2fc218889ae9a3a23b700e3d71d820966158a47228f0bf985c30958a540e7ed250b8682bc43e4c4614882a2393",
        "bdae364a21790b3498b45f828edf0b094beb25eec636bd9ba1a7e545d8bcdf46fcbfa4b527e7d1573f0e149591",
        "683b4bac020ac14f6ff7a86cbf76cf4193d54ab3df8bbfd6ff335df6f336540b4fbe67b1033a645bf71e34f30c",
        "76993a401c3854e1f1b10c439d62982b8dc7c0e95ff21b8ee27eb718af8e426ffffc010577dab6c5bf85d55822",
        "05a24afad947e5cecdfe678ea8f4e56cd1d43d777c06ccd065fd58dad022299175961fa8074920aeb98420e400",
        "b036434e9b6938836d3051d7f336fc46392b94975ce3899314356649035f4a1555c9ac44af15d9faf273169326",
        "b364aa757b9c8443eb76dca3dec0a2c5176fc2ca18c708c5bb1fbda224f36aa15b8be8d7abbd2eca7896c0621a",
        "f6ce1a46d2cb8ad62b8ee33e1f0e58710d07ca507fe56a002c55758d3c2752ed0a2ddf425f8c13383a9c056f17",
        "adc016590f45fbebd7c768431f5993c972e7c0823b9498fc591f0cf6358519d81651c3b046cb3352d72c476020",
        "052fc1baed17d94adfb282ed8cdba7526b13035b68259d003721c4d7187831399cd9276b5f327612d785dfee07",
        "ef0685fca2a197e5a459df41dd53e256529573773517711cc612a3c201cefc85cee03a22ed098f882689344b1c",
        "08b25ef660f9eaef1a565106d3525dab8cd4cce1bf71cf12f36399ac58fd4b612efdedc0c8c4da62ceebd23065",
        "7d2a701547b46d65e8191462b68ece26e85165e2135d05570aa6e6c4bcdb2774c7985e9936e59c58199820ed72",
        "4f9c798c40d9f48ecf2e7a1a4f18ce786d2cb206cfe71463cf87f837c8547d7929ccf09fd7d34e83a771023e8b",
        "ecb8de364d5c67940aef4e1045cb0a52ce7bdb94d27f55825313b3b27d98f2227a0081c305e4dba57d4e3d8cdc",
        "ce0407c1fc1f49dc14d91c64f8d74bff084d6b569e8e329a65f8911a4e22e46301db2b219f3ee461a456a7cdc4",
        "25bc2408a5de43c4ca2c389186fda27474a6a6501d7b7e98ca0cdf980c5c189e02cad3d1eb3e3b94937b80d606",
        "d8b1ffb93cbc7a4517baf348095c58ca9c5c09474a333b9aa7941ee776b6507e091171b6036ab3c06b5e9a5807",
        "ad31f44359f1b6650638b62ccbf1b233688b256d1d2eb26cbad56e544aad60373aa475c07aaf5ae6a7e9230f66",
        "92cb416ba9a240c27931488fc7be1c314cb05a5839b013fda550b14aa5c565017cfd87bd24b7cf45b541533f22",
        "f52f4b95e3027fc8e9cc7807576412fd760b130b30fa9d679f1e5ca69d84fbebc8898ca763352617b1ebed54e5",
        "35cbf1ec7ca171929f6e14e210741f014bb086cb17bb4bbcc85720194c4b9ac3c89171c47fb2ba5abef6af3b2e",
        "a11a1127292270c3da5dbc98e2c20ac9cefb8b6558f9e0ddc176b2c432c636c759dfba207e4a3ba75af508eb90",
        "9d6fc53907081a14c9816a33c1170de9d0e8f3f889dc008c7baf7fd92e510d5c89fcb25db32d084e62537734e1",
        "076b9763539fe8bae8a50ad4d099ddccb0f4a6d40ac603853d88d7964dd2b7fa2a035bc72f5c46c559939a3a75",
        "fc96c637544fb5cc26cc7cf10aa7f6ee7b6fd4b7a783acc837572e386456b4b634715a6d4b47e03ee754f051d0",
        "63e50905c2a999b1e6a0463c6e3b6d28978e85aaca4ea57dfbe7dedd1b6d93c0b8cce5f185efed964c68fa7116",
        "805e28b73870867dff595f5cd52a755d6c7b0ed772e5bf3997560851f0d1f14784d974605a298a56ad32151447",
        "5dfad34c721ee50cef70e20426c44caa34f5d8e846faf79e73498f84cb33d6fb848e11bf460fc1298c45013134",
        "7519e7283853224af69cd7c131a590aa7f7594cf678d2e7f6c7228857cd38069fb8e6738ac4d1d85b6543a4e7f"
    };

    // std::string key = "a1d0be14662b407b316740a502e4e1f92c9dab2114c54";
    std::vector<std::string> keysStrings = {
        "377584da4581359ab178636281280af489983afbbf2df",
        "ac52c248aecd20c5d076e5da8fe6d5c0d2798fa92c02e",
        "dd8825d921fcf6cb59bef92358087e4ee27a2af550728",
        "bfde3b60d139e8d7cb41b865e9179bfeb773705f63340",
        "c179ebc6c0466d58dab68f36c9b0a5354c9076afe046e",
        "93b179483dd163021404b6a3a1bcde72a0ff8571a5b02",
        "61c9d6022bff9ff45c30fe978dadfe5d4772a606670d0",
        "0cb75820ff808d723b5edab3a51b582ec284428f5332a",
        "f8ca92b5d9fe25797d4317fc73324ca89786662a16acd",
        "6f159644f0159ad17e1dd5ddd91a6cf7c62606c2715fd",
        "a45510f8374f0a0304572942dcc3a94840046205338f6",
        "c2abace32196692b8d5f519df18d49c5be90f4712a4b5",
        "58e4b4b9a5183076dbc681e9a5390e1b03fb9ad512ea4",
        "cce80d574e3ff5ad74a878c11d35f67796f30a548bee1",
        "a465b7cdcaef57e97886bce888e0149e6afa3a9667c1e",
        "67374099726c45bc648fca81bf7b883edf27bff54ee7d",
        "2e7180ab32b9456dde8d4026782b2a14f56333bcdacb3",
        "1a2b78af093ac35eb2c8969d44cb5b42c5a527f19f449",
        "ac8d4ca2fab57c1a9e6f5cb9a5a90ba34df79930e48b2",
        "793d512f2cddfbd05b34cc2ce7ea74035211ff61a8de3",
        "bf538ff191ed9cc8cce25137ca511b8f08770ddc29fef",
        "161d9532bbef3307d7170c561ce7340b5dd0cd4eaefb4",
        "686b03cd5a16e192c6f2aa33cf83fc24c9d5f42948aa4",
        "f9770cf4d10d28615ce4c52eeaef0ce8563a5db95e22d",
        "67dcaad97d14e66a8367977cb2485b2670932a3890d8e",
        "54b5e69cd381ec948baccc1691c27b6f8b1e0b10c9033",
        "58e448cdec4cc5af306c1020affe98783dee44add338c",
        "f84f8f69990737ed7bf2ce4755e732d3fd8d44ad9d34d",
        "a190b75f36372ad03d0cf1c68b05af216fee324c7a148",
        "f10d8cfac8c66fef2d5d11d24078341f68e400a191ace",
        "a6e4813cbafd4b6d4da26b161e834be47451f8ac6c76f",
        "daf4d06550e1e5b9e129363e8bf45122631eabe8abd07",
        "e805e5bcffda96ceed0682c666baa4ed4a244e3d4aeba",
        "63c1ff651a87d7a28900b5186384de54fcd673cf5f00a",
        "00ee17b4414da0a6b346d2b02d924aa072d666c6e65c4",
        "ead577868133a30b3add50983521d6d02aaf240c71ed8",
        "614f8a1ce67175e1989bad2ba6d7380ec79ce0fec6d50",
        "cb8fadca7e774ffbd9eb237de30273ce802842e32093a",
        "62ed4c612368f191af6f03857340a7db1cb72af50b123",
        "512dbb7c1a2471b30648a78d9cf7f2e973af594e5a12a",
        "a1d0be14662b407b316740a502e4e1f92c9dab2114c54",
        "996c6f20ccd1ee15c81f0ebf8c0bfa43bd9fb5eb56862",
        "685f9a4c327806f1ee7d279c9e82573a5256162cbbb7b",
        "0a2755e00c85f5041b553e3bca0ef874e6e2260792b7b",
        "61ae31120fa81a8bf32d7a023d2e6aa7096c1c97a5766",
        "46e80f5bdaee5181ba54a3a3fc223b539cb4b60e4a950",
        "7c35e75b23bad4c15fd81b0ac2dc6cb8f0c655d02b9b9",
        "32500582408a302a6a26e0299952e5a98db2efd5e8e63",
        "ee1297911685e803d9ab75ad465478be375577e486286",
        "31e48e3e2887aed03b3e0df2c949573712acf1d123ed6"
    };

    
    int steps = 6;  // We want to get the index at the 6th step
    int midIndex = binarySearchAtStep(hexStrings, steps);

    int KeyMidIndex = binarySearchAtStep(keysStrings, (steps - 2));

    std::string encrypted_flag = hex_to_bytes(hexStrings[midIndex]);
    std::string decryptor_key = keysStrings[KeyMidIndex];

    // Decrypt the encrypted data back to original flag
    std::string decrypted;
    rc4(decryptor_key, encrypted_flag, decrypted);

    // Print the decrypted (original) result
    std::cout << "Your deserve this flag: " << decrypted << std::endl;
}
