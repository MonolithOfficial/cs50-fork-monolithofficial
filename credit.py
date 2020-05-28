from cs50 import get_int


def luhn_alg(number):
    list_of_every_second = list(str(number))
    list_of_other = list(str(number))

    del list_of_every_second[-1::-2]
    multiplied_list = [int(i) * 2 for i in list_of_every_second]
    list_to_sum = []
    for k in multiplied_list:
        list_to_sum.append(k)
        if k > 9:
            list_to_sum.remove(k)
            k = int(k / 10) + (k % 10)
            list_to_sum.append(k)
    sum_of_every_second = sum(list_to_sum)
    # print(list_of_every_second)
    # print(list_to_sum)
    # print(sum_of_every_second)

    del list_of_other[-2::-2]
    # print(list_of_other)
    sum_of_other = 0
    for g in list_of_other:
        sum_of_other += int(g)
    # print(sum_of_other)
    return sum_of_every_second + sum_of_other


credit_card_input = get_int("Number: ")


if str(luhn_alg(credit_card_input))[-1] == '0' and str(credit_card_input)[:1] == '4' and (len(str(credit_card_input)) == 13 or len(str(credit_card_input)) == 16):
    print("VISA")
    # print(str(credit_card_input)[:2])

elif str(luhn_alg(credit_card_input))[-1] == '0' and len(str(credit_card_input)) == 15 and (str(credit_card_input)[:2] == '34' or str(credit_card_input)[:2] == '37'):
    print("AMEX")

elif str(luhn_alg(credit_card_input))[-1] == '0' and len(str(credit_card_input)) == 16 and (str(credit_card_input)[:2] == '51' or str(credit_card_input)[:2] == '52' or str(credit_card_input)[:2] == '53' or str(credit_card_input)[:2] == '54' or str(credit_card_input)[:2] == '55'):
    print("MASTERCARD")

else:
    print("INVALID")
    # print(luhn_alg(credit_card_input))
