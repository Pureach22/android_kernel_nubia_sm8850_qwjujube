bool __fastcall mlo_mgr_is_link_add_link_switch(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8

  v1 = *(_QWORD *)(a1 + 1360);
  return v1 && (v2 = *(_QWORD *)(v1 + 3880)) != 0 && (*(_BYTE *)(a1 + 67) & 2) != 0 && *(_DWORD *)(v2 + 168) == 65534;
}
