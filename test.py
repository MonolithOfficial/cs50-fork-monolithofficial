import os
from werkzeug.security import check_password_hash, generate_password_hash

# print(os.environ.get("HOME"))
hash_gen = generate_password_hash("Langley")
print(hash_gen)
unhash = check_password_hash(hash_gen, "Langley")
print(unhash)
