__int64 __fastcall msm_vidc_set_pipe(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  unsigned int (*v3)(void); // x8
  __int64 v5; // x4
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(a1 + 320);
  if ( !v1 )
    goto LABEL_10;
  v2 = *(_QWORD *)(v1 + 6560);
  if ( !v2 )
    goto LABEL_10;
  v3 = *(unsigned int (**)(void))(v2 + 16);
  if ( !v3 )
    goto LABEL_10;
  if ( *((_DWORD *)v3 - 1) != 1661903850 )
    __break(0x8228u);
  if ( v3() )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_80088, "err ", a1 + 340, "msm_vidc_set_pipe", v5);
      result = 4294967274LL;
    }
    else
    {
      result = 4294967274LL;
    }
  }
  else
  {
LABEL_10:
    result = ((__int64 (*)(void))msm_vidc_packetize_control)();
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
