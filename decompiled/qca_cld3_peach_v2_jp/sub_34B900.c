__int64 __fastcall sub_34B900(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  if ( !a8 )
    JUMPOUT(0x445A4C);
  return _hdd_objmgr_get_vdev_by_user(a1, a2, a3);
}
