__int64 __fastcall uetm_disable(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x0
  void (__fastcall *v4)(__int64, int *, __int64, __int64, __int64); // x8
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(*(_QWORD *)(result + 152) + 152LL);
  if ( (unsigned int)*(_QWORD *)(result + 968) == 1 )
  {
    v2 = result;
    v3 = ph;
    v4 = *(void (__fastcall **)(__int64, int *, __int64, __int64, __int64))(ops + 24);
    v5 = *(_DWORD *)(v1 + 40);
    if ( *((_DWORD *)v4 - 1) != 1737159351 )
      __break(0x8228u);
    v4(v3, &v5, 1430606925, 1, 4);
    coresight_trace_id_put_system_id(*(unsigned __int8 *)(v1 + 44));
    result = coresight_csr_set_etr_atid(v2, *(unsigned __int8 *)(v1 + 44), 0, 0);
    *(_QWORD *)(v2 + 968) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
