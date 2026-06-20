__int64 __fastcall cm_send_ies_for_roam_invoke(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  __int64 v13; // x3
  _DWORD *v14; // x8
  __int64 v15; // x0
  __int64 v16; // x1

  context = _cds_get_context(54, (__int64)"cm_send_ies_for_roam_invoke", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return 16;
  v13 = *(unsigned int *)(a1 + 16);
  v14 = (_DWORD *)context[390];
  v15 = context[2];
  v16 = *(unsigned __int8 *)(a1 + 104);
  if ( *(v14 - 1) != -1704355693 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))v14)(v15, v16, a2, v13);
}
