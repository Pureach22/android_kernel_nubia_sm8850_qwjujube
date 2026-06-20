__int64 __fastcall qmp_sdca_dmic_prepare(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x8
  __int64 v4; // x10

  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 96) + 24LL) + 152LL);
  v3 = *(_QWORD *)(v2 + 16);
  if ( !v3 )
    return 4294967274LL;
  v4 = *(unsigned int *)(a2 + 8);
  if ( (((unsigned __int64)*(int *)(v2 + 200) >> v4) & 1) == 0 )
    return 0;
  if ( (unsigned int)v4 < 3 )
    return ((__int64 (__fastcall *)(__int64, _QWORD, bool, _QWORD))stream_agg_prepare_channel)(
             a1,
             *(unsigned __int8 *)(v2 + v4 + 204),
             (_DWORD)v4 == 1,
             *(unsigned __int8 *)(v3 + 64));
  __break(0x5512u);
  return qmp_disable_regulator(a1);
}
