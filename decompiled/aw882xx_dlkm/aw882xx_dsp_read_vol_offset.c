__int64 __fastcall aw882xx_dsp_read_vol_offset(__int64 a1, void *a2)
{
  __int64 result; // x0
  __int64 *v4; // x9
  __int64 v5; // x1
  unsigned int v6; // w19

  result = aw_read_msg_from_dsp_v_1_0_0_0(a2, 4u);
  if ( (_DWORD)result )
  {
    v4 = *(__int64 **)(a1 + 112);
    v5 = v4[14];
    if ( !v5 )
      v5 = *v4;
    v6 = result;
    printk(&unk_274F6, v5, "aw882xx_dsp_read_vol_offset");
    return v6;
  }
  return result;
}
