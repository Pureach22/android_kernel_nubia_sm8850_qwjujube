__int64 __fastcall sub_36B1AC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 _X7)
{
  __int64 v12; // x4

  __asm { LDLARB          W4, [X7] }
  v12 = _OFF;
  __asm { LDLARB          W4, [X7] }
  return hdd_vdev_ready(a1, a2, a3, a4, v12);
}
