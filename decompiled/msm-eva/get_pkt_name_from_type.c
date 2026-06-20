void *__fastcall get_pkt_name_from_type(unsigned int a1)
{
  __int64 v1; // x8
  __int64 v2; // x9

  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(cvp_driver + 48) + 264LL) + 56LL) == 1 )
  {
    if ( a1 - 67178497 <= 0x1FF )
    {
      v1 = cvp_hfi_defs + 84LL * a1;
      v2 = -1348026352;
      return (void *)(v1 + (v2 & 0xFFFF0000FFFFFFFFLL | 0xFFFE00000000LL));
    }
    if ( a1 - 67244033 <= 0x1FF )
    {
      v1 = cvp_hfi_msg_defs + 84LL * a1;
      v2 = -1353531376;
      return (void *)(v1 + (v2 & 0xFFFF0000FFFFFFFFLL | 0xFFFE00000000LL));
    }
  }
  return &unk_871D4;
}
