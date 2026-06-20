__int64 __fastcall ufs_qcom_get_cur_therm_state(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int128 v7; // q19
  __int128 v8; // q22
  __int64 v9; // x8

  v9 = *(_QWORD *)(*(_QWORD *)(a1 + 944) + 152LL);
  if ( v9 )
  {
    *a2 = *(_QWORD *)(*(_QWORD *)(v9 + 184) + 488LL);
    return 0;
  }
  else
  {
    __break(0x800u);
    *(_OWORD *)(a7 - 656) = v7;
    *(_OWORD *)(a7 - 640) = v8;
    return ufs_qcom_set_cur_therm_state();
  }
}
