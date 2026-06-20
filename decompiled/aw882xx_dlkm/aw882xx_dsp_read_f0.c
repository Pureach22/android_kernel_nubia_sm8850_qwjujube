__int64 __fastcall aw882xx_dsp_read_f0(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 *v4; // x8
  __int64 v5; // x1
  __int64 *v6; // x8
  unsigned int v7; // w20
  __int64 v8; // x1

  if ( *(_DWORD *)(a1 + 52) >= 8u )
  {
    v4 = *(__int64 **)(a1 + 112);
    v5 = v4[14];
    if ( !v5 )
      v5 = *v4;
    printk(&unk_27130, v5, "aw882xx_dsp_read_f0");
    return 4294967274LL;
  }
  else
  {
    result = aw882xx_dsp_read_dsp_msg(a1, a2, a2, 4u);
    if ( (_DWORD)result )
    {
      v6 = *(__int64 **)(a1 + 112);
      v7 = result;
      v8 = v6[14];
      if ( !v8 )
        v8 = *v6;
      printk(&unk_247E4, v8, "aw882xx_dsp_read_f0");
      return v7;
    }
  }
  return result;
}
