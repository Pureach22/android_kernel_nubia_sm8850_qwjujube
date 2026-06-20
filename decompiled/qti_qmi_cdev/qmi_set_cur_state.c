__int64 __fastcall qmi_set_cur_state(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  int v4; // w20

  v2 = *(_QWORD *)(a1 + 944);
  if ( !v2 || *(unsigned int *)(v2 + 108) < a2 )
    return 4294967274LL;
  if ( *(_DWORD *)(v2 + 104) == a2 )
    return 0;
  if ( *(_BYTE *)(v2 + 72) == 1 )
  {
    v4 = a2;
    result = qmi_tmd_send_state_request(*(_QWORD *)(a1 + 944), a2);
    LODWORD(a2) = v4;
  }
  else
  {
    result = 0;
  }
  *(_DWORD *)(v2 + 104) = a2;
  return result;
}
