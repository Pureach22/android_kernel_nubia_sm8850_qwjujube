__int64 __fastcall rmnet_aps_do_post_queue(__int64 a1, __int64 a2)
{
  if ( *(_BYTE *)(a1 + 3176)
    && *(_QWORD *)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 16LL)
    && aps_packet_expire_kt
    && ktime_get_with_offset(1) - *(_QWORD *)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 16LL) > aps_packet_expire_kt )
  {
    return 4294967186LL;
  }
  else
  {
    return 0;
  }
}
