bool __fastcall csr_is_bssid_match(const void *a1, __int64 a2)
{
  bool v3; // zf
  _BOOL8 result; // x0
  int v6; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int16 v7; // [xsp+Ch] [xbp-14h]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  v6 = 0;
  qdf_mem_copy(&v6, a1, 6u);
  result = !(v6 | v7)
        || (v6 == -1 ? (v3 = (__int16)v7 == -1) : (v3 = 0), v3)
        || *(_DWORD *)a2 == v6 && *(unsigned __int16 *)(a2 + 4) == v7;
  _ReadStatusReg(SP_EL0);
  return result;
}
