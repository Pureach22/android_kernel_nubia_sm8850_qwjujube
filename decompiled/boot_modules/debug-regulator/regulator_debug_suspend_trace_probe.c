void __fastcall regulator_debug_suspend_trace_probe(__int64 a1, const char *a2, int a3, char a4)
{
  __int64 v4; // x1
  _UNKNOWN **v5; // x21
  void ***v6; // x26
  int (__fastcall *v7)(_QWORD); // x8
  void *v8; // x0
  int voltage_rdev; // w27
  __int64 (__fastcall *v10)(_QWORD); // x8
  void **v11; // x8
  void *v12; // x1
  int v13; // w4
  void **v14; // x8
  void *v15; // x1
  void **v16; // x8
  void *v17; // x1
  void *v18; // x0
  void ***v19; // x26
  void **i; // x27
  void **v21; // t1
  const char *v22; // x1
  void **v23; // x8

  if ( a3 >= 1 && (a4 & 1) != 0 && !strcmp("machine_suspend", a2) )
  {
    printk(&unk_80D8, v4);
    v5 = (_UNKNOWN **)debug_reg_list;
    if ( debug_reg_list != (_UNKNOWN *)&debug_reg_list )
    {
      while ( 1 )
      {
        v6 = (void ***)v5[4];
        if ( !v6[162] )
          break;
        if ( ((_BYTE)v6[163] & 1) == 1 )
          goto LABEL_16;
LABEL_14:
        v5 = (_UNKNOWN **)*v5;
        if ( v5 == &debug_reg_list )
          return;
      }
      v7 = *((int (__fastcall **)(_QWORD))(*v6)[8] + 16);
      if ( v7 )
      {
        v8 = v5[4];
        if ( *((_DWORD *)v7 - 1) != -741648806 )
          __break(0x8228u);
        if ( v7(v8) < 1 )
          goto LABEL_14;
      }
LABEL_16:
      voltage_rdev = regulator_get_voltage_rdev(v6);
      v10 = *((__int64 (__fastcall **)(_QWORD))(*v6)[8] + 18);
      if ( v10 )
      {
        if ( *((_DWORD *)v10 - 1) != 830785035 )
          __break(0x8228u);
        v13 = v10(v6);
        if ( voltage_rdev != -1 && v13 != -1 )
        {
          v14 = v6[143];
          if ( !v14 || (v15 = *v14) == nullptr )
          {
            if ( **v6 )
              v15 = **v6;
            else
              v15 = &unk_7D61;
          }
          printk(&unk_81FC, v15);
          goto LABEL_42;
        }
        if ( voltage_rdev == -1 )
        {
          if ( v13 == -1 )
          {
LABEL_18:
            v11 = v6[143];
            if ( !v11 || (v12 = *v11) == nullptr )
            {
              if ( **v6 )
                v12 = **v6;
              else
                v12 = &unk_7D61;
            }
            printk(&unk_8084, v12);
            goto LABEL_42;
          }
          v23 = v6[143];
          if ( !v23 || (v17 = *v23) == nullptr )
          {
            if ( **v6 )
              v17 = **v6;
            else
              v17 = &unk_7D61;
          }
          v18 = &unk_7E71;
LABEL_41:
          printk(v18, v17);
LABEL_42:
          if ( *((_DWORD *)v6 + 4) )
            printk(&unk_7CBC, "Device-Supply");
          v21 = v6[5];
          v19 = v6 + 5;
          for ( i = v21; i != (void **)v19; i = (void **)*i )
          {
            if ( i[9] )
              v22 = (const char *)i[9];
            else
              v22 = "(null)-(null)";
            printk(&unk_7D8E, v22);
          }
          goto LABEL_14;
        }
      }
      else if ( voltage_rdev == -1 )
      {
        goto LABEL_18;
      }
      v16 = v6[143];
      if ( !v16 || (v17 = *v16) == nullptr )
      {
        if ( **v6 )
          v17 = **v6;
        else
          v17 = &unk_7D61;
      }
      v18 = &unk_81AC;
      goto LABEL_41;
    }
  }
}
