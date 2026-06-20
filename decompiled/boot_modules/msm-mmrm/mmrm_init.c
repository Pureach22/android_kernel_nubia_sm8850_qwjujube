__int64 __fastcall mmrm_init(__int64 a1)
{
  __int64 result; // x0
  __int64 (__fastcall *v3)(_QWORD); // x8
  unsigned int v4; // w19

  result = mmrm_get_clk_mgr_ops(a1);
  if ( (_DWORD)result )
    goto LABEL_5;
  v3 = **(__int64 (__fastcall ***)(_QWORD))(a1 + 104);
  if ( *((_DWORD *)v3 - 1) != -1066802076 )
    __break(0x8228u);
  result = v3(a1);
  if ( (_DWORD)result )
  {
LABEL_5:
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
    {
      v4 = result;
      printk(&unk_CFBA, "err ", "mmrm_init");
      return v4;
    }
  }
  return result;
}
