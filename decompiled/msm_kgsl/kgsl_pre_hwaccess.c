bool __fastcall kgsl_pre_hwaccess(__int64 a1)
{
  _BOOL8 result; // x0

  if ( !*(_QWORD *)(a1 + 11112) )
    __break(0x800u);
  result = gmu_core_gpmu_isenabled(a1);
  if ( !result && ((*(_QWORD *)(a1 + 9128) & 2) == 0 || (*(_QWORD *)(a1 + 9128) & 4) == 0) )
    __break(0x800u);
  return result;
}
