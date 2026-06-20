__int64 __fastcall store_anon_migrate(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w0
  int v6; // w8
  unsigned int v14; // w10
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v5 = kstrtoint(a3, 0, &v15);
  if ( v5 < 0 )
  {
    a4 = v5;
  }
  else
  {
    v6 = v15;
    _X9 = &target_migrate_pages;
    __asm { PRFM            #0x11, [X9] }
    do
      v14 = __ldxr((unsigned int *)&target_migrate_pages);
    while ( __stxr(v14 + v6, (unsigned int *)&target_migrate_pages) );
    if ( (fill_movable_zone_work & 1) == 0 )
      queue_work_on(32, migrate_wq, &fill_movable_zone_work);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
