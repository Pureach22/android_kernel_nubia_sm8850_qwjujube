__int64 __fastcall cam_hw_cdm_dump_scratch_registors(__int64 a1)
{
  __int64 v2; // x23
  __int64 result; // x0
  _QWORD *v4; // x8
  unsigned __int64 v5; // x20
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 3680);
  v6 = 0;
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v2 + 232) + 28LL), &v6);
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             1,
             1,
             "cam_hw_cdm_dump_scratch_registors",
             264,
             "dump core en=%x",
             v6);
  v4 = *(_QWORD **)(v2 + 232);
  if ( *(_DWORD *)(v4[9] + 12LL) )
  {
    v5 = 0;
    do
    {
      if ( v5 == 12 )
        __break(0x5512u);
      cam_cdm_read_hw_reg(a1, **(_DWORD **)(*v4 + 8 * v5 + 160), &v6);
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 1,
                 1,
                 "cam_hw_cdm_dump_scratch_registors",
                 270,
                 "dump scratch%d=%x",
                 v5,
                 v6);
      v4 = *(_QWORD **)(v2 + 232);
      ++v5;
    }
    while ( v5 < *(unsigned int *)(v4[9] + 12LL) );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
