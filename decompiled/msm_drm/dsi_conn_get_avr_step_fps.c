__int64 __fastcall dsi_conn_get_avr_step_fps(__int64 a1)
{
  __int64 v1; // x8

  if ( a1 && (v1 = *(_QWORD *)(a1 + 3248)) != 0 )
    return *(unsigned int *)(v1 + 2404);
  else
    return 4294967274LL;
}
