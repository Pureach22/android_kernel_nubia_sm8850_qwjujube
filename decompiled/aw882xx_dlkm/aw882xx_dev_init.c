__int64 __fastcall aw882xx_dev_init(__int64 a1, _DWORD *a2)
{
  __int64 *v3; // x8
  __int64 v4; // x1
  __int64 result; // x0
  void (__fastcall *v6)(__int64, __int64, __int64); // x8
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 *v10; // x8
  __int64 v11; // x1
  __int64 v12; // x1
  __int64 (__fastcall *v13)(_QWORD); // x8
  __int64 *v14; // x8
  __int64 v15; // x1
  __int64 v16; // x0
  __int64 *v17; // x8
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x3
  void (__fastcall *v21)(__int64, __int64, __int64, __int64); // x8
  __int64 v22; // x0
  __int64 *v23; // x8
  __int64 v24; // x1

  if ( a2 )
  {
    if ( (unsigned int)aw882xx_dev_parse_acf(a1, a2) )
    {
      if ( a1 )
      {
        v16 = *(_QWORD *)(a1 + 640);
        if ( v16 )
        {
          kfree(v16);
          *(_QWORD *)(a1 + 640) = 0;
          *(_DWORD *)(a1 + 624) = 0;
        }
      }
      v17 = *(__int64 **)(a1 + 112);
      v18 = v17[14];
      if ( !v18 )
        v18 = *v17;
      printk(&unk_25ADC, v18, "aw882xx_dev_init");
      return 4294967274LL;
    }
    else
    {
      v6 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 1152);
      v7 = *(_QWORD *)(a1 + 120);
      v8 = *(unsigned int *)(a1 + 928);
      v9 = *(unsigned int *)(a1 + 932);
      if ( *((_DWORD *)v6 - 1) != -1860236611 )
        __break(0x8228u);
      v6(v7, v8, v9);
      v10 = *(__int64 **)(a1 + 112);
      v11 = v10[14];
      if ( !v11 )
        v11 = *v10;
      printk(&unk_274D3, v11, "aw_dev_soft_reset");
      v12 = *(unsigned int *)(a1 + 200);
      if ( (_DWORD)v12 != 255 )
      {
        v19 = *(unsigned int *)(a1 + 204);
        v20 = *(unsigned int *)(a1 + 208);
        v21 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
        v22 = *(_QWORD *)(a1 + 120);
        if ( *((_DWORD *)v21 - 1) != 370515439 )
          __break(0x8228u);
        v21(v22, v12, v19, v20);
        v23 = *(__int64 **)(a1 + 112);
        v24 = v23[14];
        if ( !v24 )
          v24 = *v23;
        printk(&unk_25B06, v24, "aw_dev_switch");
      }
      *(_WORD *)(a1 + 48) = 0;
      result = aw_dev_reg_fw_update(a1);
      if ( (result & 0x80000000) == 0 )
      {
        v13 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1208);
        if ( !v13 )
          goto LABEL_16;
        if ( *((_DWORD *)v13 - 1) != -2003566296 )
          __break(0x8228u);
        result = v13(a1);
        if ( !(_DWORD)result )
        {
LABEL_16:
          *(_DWORD *)a1 = 1;
          aw882xx_device_stop(a1);
          v14 = *(__int64 **)(a1 + 112);
          *(_DWORD *)(a1 + 76) = 0;
          *(_DWORD *)(a1 + 92) = 0;
          v15 = v14[14];
          if ( !v15 )
            v15 = *v14;
          printk(&unk_270B1, v15, "aw882xx_dev_init");
          return 0;
        }
      }
    }
  }
  else
  {
    v3 = *(__int64 **)(a1 + 112);
    v4 = v3[14];
    if ( !v4 )
      v4 = *v3;
    printk(&unk_23B79, v4, "aw882xx_dev_init");
    return 4294967284LL;
  }
  return result;
}
