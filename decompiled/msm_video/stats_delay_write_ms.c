__int64 __fastcall stats_delay_write_ms(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 v5; // x4
  unsigned int v8; // w0
  __int64 result; // x0
  unsigned int v10; // w8
  char v11; // w9
  __int64 v12; // x4
  _QWORD *v13; // x23
  unsigned int v14; // [xsp+4h] [xbp-1Ch] BYREF
  _QWORD v15[3]; // [xsp+8h] [xbp-18h] BYREF

  v15[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  memset(v15, 0, 15);
  v14 = 0;
  if ( !v4 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83566, "err ", 0xFFFFFFFFLL, "codec", "stats_delay_write_ms");
    goto LABEL_23;
  }
  v5 = *a4;
  if ( ((unsigned __int64)(a3 - 15) < 0xFFFFFFFFFFFFFFF2LL || v5) && (msm_vidc_debug & 1) != 0 )
  {
    v13 = a4;
    printk(&unk_908F3, "err ", 0xFFFFFFFFLL, "codec", v5);
    a4 = v13;
  }
  if ( (simple_write_to_buffer(v15, 14, a4, a2, a3) & 0x80000000) == 0 )
  {
    v8 = kstrtoint(v15, 0, &v14);
    if ( v8 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_89BAE, "err ", 0xFFFFFFFFLL, "codec", v8);
      result = -22;
      goto LABEL_24;
    }
    v10 = v14;
    if ( v14 <= 0xC8 )
      v10 = 200;
    v11 = msm_vidc_debug;
    if ( v10 >= 0x2710 )
      v12 = 10000;
    else
      v12 = v10;
    v14 = v12;
    *(_QWORD *)(v4 + 4512) = v12;
    if ( (v11 & 2) != 0 )
      printk(&unk_85882, "high", 0xFFFFFFFFLL, "codec", v12);
LABEL_23:
    result = 0;
    goto LABEL_24;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_8FDC9, "err ", 0xFFFFFFFFLL, "codec", "stats_delay_write_ms");
  result = -14;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
