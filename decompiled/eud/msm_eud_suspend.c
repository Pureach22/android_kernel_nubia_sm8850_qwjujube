__int64 __fastcall msm_eud_suspend(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_BYTE *)(v1 + 625) == 1 )
  {
    v2 = *(_QWORD *)(v1 + 640);
    if ( v2 )
    {
      clk_disable(*(_QWORD *)(v1 + 640));
      clk_unprepare(v2);
    }
  }
  return 0;
}
