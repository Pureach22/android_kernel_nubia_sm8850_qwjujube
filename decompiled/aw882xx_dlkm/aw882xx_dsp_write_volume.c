__int64 __fastcall aw882xx_dsp_write_volume(__int64 a1, const void *a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 *v5; // x9
  __int64 v6; // x1
  unsigned int v7; // w19

  result = aw_write_msg_to_dsp_v_1_0_0_0(a1, 268516692, a2, a3);
  if ( (_DWORD)result )
  {
    v5 = *(__int64 **)(a1 + 112);
    v6 = v5[14];
    if ( !v6 )
      v6 = *v5;
    v7 = result;
    printk(&unk_232C7, v6, "aw882xx_dsp_write_volume");
    return v7;
  }
  return result;
}
