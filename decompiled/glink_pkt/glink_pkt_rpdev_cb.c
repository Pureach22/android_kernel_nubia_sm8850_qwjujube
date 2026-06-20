__int64 __fastcall glink_pkt_rpdev_cb(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = glink_pkt_rpdev_no_copy_cb;
  if ( !*(_BYTE *)(*(_QWORD *)(a1 + 152) + 1144LL) )
    v1 = glink_pkt_rpdev_copy_cb;
  if ( *((_DWORD *)v1 - 1) != -384116476 )
    __break(0x8228u);
  return v1();
}
