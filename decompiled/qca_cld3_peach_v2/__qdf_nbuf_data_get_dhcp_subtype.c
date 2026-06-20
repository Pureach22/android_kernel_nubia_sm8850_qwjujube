__int64 __fastcall _qdf_nbuf_data_get_dhcp_subtype(_BYTE *a1)
{
  if ( a1[282] == 53 && a1[283] == 1 && (unsigned __int8)(a1[284] - 1) <= 7u )
    return dword_B35368[(unsigned __int8)(a1[284] - 1)];
  else
    return 0;
}
