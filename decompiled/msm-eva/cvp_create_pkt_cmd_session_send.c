__int64 __fastcall cvp_create_pkt_cmd_session_send(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  unsigned int pkt_index; // w0
  unsigned __int64 StatusReg; // x9

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    if ( *a2 <= 0x960u
      && a2[2] == (HIDWORD(a1) ^ (unsigned int)a1)
      && (pkt_index = get_pkt_index(a2), (pkt_index & 0x80000000) == 0)
      && *(_DWORD *)(cvp_hfi_defs + 84LL * pkt_index + 4) == a2[1] )
    {
      return 0;
    }
    else
    {
      result = 4294967274LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_8A908, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        return 4294967274LL;
      }
    }
  }
  return result;
}
