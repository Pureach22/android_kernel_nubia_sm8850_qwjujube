__int64 __fastcall ping_config(char *a1)
{
  char *v1; // x0
  unsigned int v2; // w20
  void *v3; // x0
  unsigned int v4; // w0
  char *v6; // x0
  char *v7; // x0
  int v8; // w8
  int v9; // w20
  int v10; // w0
  unsigned int v11; // w8
  char *v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = a1;
  v1 = strsep(v12, " ");
  if ( !v1 )
    goto LABEL_2;
  v4 = kstrtoint(v1, 0, &test_params);
  if ( (v4 & 0x80000000) != 0 )
  {
LABEL_4:
    v2 = v4;
    v3 = &unk_AF38;
    goto LABEL_5;
  }
  v6 = strsep(v12, " ");
  if ( !v6 )
    goto LABEL_2;
  v4 = kstrtoint(v6, 0, &qword_B680);
  if ( (v4 & 0x80000000) != 0 )
    goto LABEL_4;
  v7 = strsep(v12, " ");
  if ( !v7 )
  {
LABEL_2:
    v2 = -22;
    v3 = &unk_B2D9;
LABEL_5:
    printk(v3, "ipclite_test", "parse_param");
    goto LABEL_6;
  }
  v4 = kstrtoint(v7, 0, &qword_B694);
  if ( (v4 & 0x80000000) != 0 )
    goto LABEL_4;
  v8 = qword_B694;
  if ( (unsigned int)(qword_B694 - 6) > 0xFFFFFFFA )
  {
    if ( (unsigned int)qword_B694 <= HIDWORD(test_params) )
      goto LABEL_16;
    printk(&unk_A967, "ipclite_test", "ping_config");
    v8 = HIDWORD(test_params);
  }
  else
  {
    printk(&unk_AC26, "ipclite_test", "ping_config");
    v8 = 1;
  }
  LODWORD(qword_B694) = v8;
LABEL_16:
  if ( ((unsigned int)qword_B688 & HIDWORD(qword_B680)) != 0 )
  {
    v10 = _sw_hweight64((int)(qword_B688 & HIDWORD(qword_B680)));
    v8 = qword_B694;
    v9 = v10;
  }
  else
  {
    v9 = 1;
  }
  if ( (unsigned int)(test_params * v9 * v8) >= 0x3E9 )
  {
    printk(&unk_A646, "ipclite_test", "ping_config");
    v11 = 0x3E8u / ((int)qword_B694 * v9);
LABEL_23:
    LODWORD(test_params) = v11;
    goto LABEL_24;
  }
  if ( (unsigned int)test_params > HIDWORD(test_params) )
  {
    printk(&unk_A2C0, "ipclite_test", "ping_config");
    v11 = 1;
    goto LABEL_23;
  }
LABEL_24:
  if ( (unsigned int)(qword_B680 - 4001) <= 0xFFFFF05F )
  {
    printk(&unk_B216, "ipclite_test", "ping_config");
    LODWORD(qword_B680) = 1;
  }
  printk(&unk_AAAD, "ipclite_test", "ping_config");
  printk(&unk_A9E5, "ipclite_test", "ping_config");
  printk(&unk_AF80, "ipclite_test", "ping_config");
  printk(&unk_A302, "ipclite_test", "ping_config");
  v2 = 0;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return v2;
}
