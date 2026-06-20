bool __fastcall cm_is_connect_req_reassoc(__int64 a1)
{
  _BOOL8 result; // x0

  _ReadStatusReg(SP_EL0);
  result = *(_DWORD *)(a1 + 14) | *(unsigned __int16 *)(a1 + 18)
        && (*(_DWORD *)(a1 + 8) | *(unsigned __int16 *)(a1 + 12) || *(_DWORD *)(a1 + 53)
                                                                  | *(unsigned __int16 *)(a1 + 57))
        && (*(_DWORD *)(a1 + 60) || *(_DWORD *)(a1 + 64));
  _ReadStatusReg(SP_EL0);
  return result;
}
