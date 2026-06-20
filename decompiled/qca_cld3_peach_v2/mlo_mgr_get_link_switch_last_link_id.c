__int64 __fastcall mlo_mgr_get_link_switch_last_link_id(__int64 a1)
{
  if ( a1 && (*(_BYTE *)(a1 + 67) & 2) != 0 )
    return *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(a1 + 1360) + 3880LL) + 145LL);
  else
    return 255;
}
