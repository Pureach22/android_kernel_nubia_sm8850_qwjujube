__int64 __fastcall osif_cm_get_assoc_rsp_ie_data(__int64 result, _QWORD *a2, _QWORD *a3)
{
  unsigned int v3; // w8

  v3 = *(_DWORD *)result;
  if ( *(_DWORD *)result && v3 >= 7 )
  {
    if ( *(_QWORD *)(result + 8) )
    {
      *a2 = v3 - 6;
      *a3 = *(_QWORD *)(result + 8) + 6LL;
    }
  }
  return result;
}
