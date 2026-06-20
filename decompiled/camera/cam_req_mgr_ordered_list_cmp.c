__int64 __fastcall cam_req_mgr_ordered_list_cmp(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8
  unsigned int v4; // w9
  bool v5; // cc
  unsigned int v6; // w8

  v3 = *(_DWORD *)(a2 + 16);
  v4 = *(_DWORD *)(a3 + 16);
  v5 = v3 > v4;
  if ( v3 >= v4 )
    v6 = 0;
  else
    v6 = -1;
  if ( v5 )
    return 1;
  else
    return v6;
}
