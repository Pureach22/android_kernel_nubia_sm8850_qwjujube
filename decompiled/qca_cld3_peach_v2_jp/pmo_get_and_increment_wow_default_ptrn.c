__int64 __fastcall pmo_get_and_increment_wow_default_ptrn(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x19
  unsigned int v11; // w20
  __int64 v12; // x8
  __int64 *v13; // x0
  __int64 v14; // x8
  __int64 v15; // x9

  context = _cds_get_context(51, (__int64)"pmo_get_and_increment_wow_default_ptrn", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( *(_BYTE *)(*a1 + 955) == 1 )
  {
    qdf_spin_lock_bh_12(a1 + 132);
    v11 = *((unsigned __int8 *)a1 + 1030);
    v12 = a1[133];
    *((_BYTE *)a1 + 1030) = v11 + 1;
    if ( (v12 & 1) != 0 )
    {
      a1[133] = v12 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 132);
      goto LABEL_7;
    }
    v13 = a1 + 132;
  }
  else
  {
    qdf_spin_lock_bh_12(*a1 + 1040);
    v11 = *(unsigned __int8 *)(*a1 + 944);
    *(_BYTE *)(*a1 + 944) = v11 + 1;
    v14 = *a1;
    v15 = *(_QWORD *)(*a1 + 1048);
    if ( (v15 & 1) != 0 )
    {
      *(_QWORD *)(v14 + 1048) = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v14 + 1040);
      goto LABEL_7;
    }
    v13 = (__int64 *)(v14 + 1040);
  }
  raw_spin_unlock(v13);
LABEL_7:
  ucfg_pmo_get_num_wow_filters(*context);
  return v11;
}
