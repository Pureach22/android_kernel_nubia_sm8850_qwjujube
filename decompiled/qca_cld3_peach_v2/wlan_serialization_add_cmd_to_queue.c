__int64 __fastcall wlan_serialization_add_cmd_to_queue(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        char a4,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v13; // w8
  char v15; // w8
  _QWORD *v16; // x1

  if ( !a1 || !a2 || !a3 )
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: Input arguments are not valid",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wlan_serialization_add_cmd_to_queue");
    return 6;
  }
  v13 = *(_DWORD *)(a1 + 16);
  if ( v13 == *(_DWORD *)(a1 + 20) )
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: Queue size reached max %d, fail to add type %d id %d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wlan_serialization_add_cmd_to_queue",
      v13,
      *(unsigned int *)(a2 + 32),
      *(unsigned int *)(a2 + 36));
    return 3;
  }
  v15 = *(_BYTE *)(a2 + 52);
  v16 = (_QWORD *)(a2 + 16LL * (a5 != 0));
  if ( (v15 & 1) != 0 )
  {
    if ( (unsigned int)qdf_list_insert_front((_QWORD *)a1, v16) )
      return 6;
  }
  else if ( (unsigned int)qdf_list_insert_back((_QWORD *)a1, v16) )
  {
    return 6;
  }
  return a4 != 0;
}
