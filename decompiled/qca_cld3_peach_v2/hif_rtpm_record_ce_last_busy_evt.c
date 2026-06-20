__int64 __fastcall hif_rtpm_record_ce_last_busy_evt(__int64 result, unsigned __int64 a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x9

  if ( result )
  {
    if ( a2 >= 0xC )
    {
      __break(0x5512u);
      return hif_rtpm_mark_last_busy(result);
    }
    else
    {
      v2 = *(_QWORD **)(gp_hif_rtpm_ctx + 8 * a2 + 320);
      if ( v2 )
      {
        v3 = v2[1] + 1LL;
        ++*v2;
        v2[1] = v3;
        __isb(0xFu);
        v2[(v3 & 0xF) + 2] = _ReadStatusReg(CNTVCT_EL0);
      }
    }
  }
  return result;
}
