__int64 __fastcall nb_fan_parse_dt(_QWORD *a1)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 next_available_child; // x0
  __int64 v5; // x1
  unsigned int v6; // w21
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned __int8 **v9; // x21
  unsigned __int8 *property; // x0
  int v11; // w8
  unsigned __int8 *v12; // x26
  unsigned __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x0
  __int64 v16; // x10
  __int64 v17; // x8
  int v18; // w9
  __int64 v19; // x8
  __int64 (__fastcall *v20)(__int64, __int64, __int64 *); // x8
  unsigned int v21; // w0
  unsigned int v22; // w19
  void *v23; // x0
  __int64 v24; // x3
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  __int64 v27; // [xsp+8h] [xbp-18h]
  __int64 v28; // [xsp+10h] [xbp-10h]
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v27 = 0;
  v28 = 0;
  v26 = 0;
  v3 = *(_QWORD *)(v2 + 744);
  next_available_child = of_get_next_available_child(v3, 0);
  if ( next_available_child )
  {
    v5 = next_available_child;
    v6 = -1;
    do
    {
      v5 = of_get_next_available_child(v3, v5);
      ++v6;
    }
    while ( v5 );
    if ( v6 < 0x7FFFFFFF )
    {
      if ( v6 )
      {
        printk(&unk_7DEF, "NB_FAN", "nb_fan_parse_dt", 679);
        v22 = -22;
        goto LABEL_32;
      }
      v7 = devm_kmalloc(*a1, 168, 3520);
      a1[1] = v7;
      if ( !v7 )
      {
        printk(&unk_7D83, "NB_FAN", "nb_fan_parse_dt", 701);
        v22 = -12;
        goto LABEL_32;
      }
      v8 = of_get_next_available_child(v3, 0);
      if ( !v8 )
      {
LABEL_23:
        v22 = 0;
        goto LABEL_32;
      }
      v9 = (unsigned __int8 **)v8;
      while ( 1 )
      {
        property = (unsigned __int8 *)of_get_property(v9, "label", 0);
        if ( !property )
        {
          property = *v9;
          if ( !*v9 )
          {
            v23 = &unk_7F6D;
            v24 = 708;
            goto LABEL_27;
          }
        }
        v11 = *property - 102;
        if ( *property == 102 && (v11 = property[1] - 97, property[1] == 97) )
        {
          if ( property[2] != 110 )
            goto LABEL_9;
        }
        else if ( v11 )
        {
          goto LABEL_9;
        }
        if ( a1[1] )
        {
          v12 = property;
          v13 = devm_fwnode_pwm_get(*a1, v9 + 3, 0);
          if ( v13 >= 0xFFFFFFFFFFFFF001LL )
          {
            if ( (_DWORD)v13 == -517 )
            {
              v22 = -517;
            }
            else
            {
              v22 = v13;
              printk(&unk_8076, "NB_FAN", "nb_fan_parse_dt", 725);
            }
            goto LABEL_32;
          }
          *(_QWORD *)(a1[1] + 32LL) = v12;
          *(_QWORD *)(a1[1] + 104LL) = v13;
          v14 = *(_QWORD *)(a1[1] + 104LL);
          v15 = *(_QWORD *)(v14 + 24);
          v16 = *(_QWORD *)(v14 + 32);
          v17 = *(_QWORD *)(v14 + 64);
          v18 = *(_DWORD *)(v14 + 40);
          v27 = 0;
          v28 = v17;
          v19 = *(_QWORD *)(v15 + 912);
          LODWORD(v28) = v18;
          v26 = v16;
          v20 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(v19 + 24);
          WORD2(v28) = 0;
          if ( *((_DWORD *)v20 - 1) != -573532208 )
            __break(0x8228u);
          v21 = v20(v15, v14, &v26);
          if ( v21 )
          {
            v22 = v21;
            printk(&unk_7ED7, "NB_FAN", "nb_fan_parse_dt", 737);
            goto LABEL_32;
          }
          printk(&unk_7B10, "NB_FAN", "nb_fan_parse_dt", 740);
        }
LABEL_9:
        v9 = (unsigned __int8 **)of_get_next_available_child(v3, v9);
        if ( !v9 )
          goto LABEL_23;
      }
    }
  }
  v23 = &unk_801D;
  v24 = 674;
LABEL_27:
  printk(v23, "NB_FAN", "nb_fan_parse_dt", v24);
  v22 = -19;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return v22;
}
