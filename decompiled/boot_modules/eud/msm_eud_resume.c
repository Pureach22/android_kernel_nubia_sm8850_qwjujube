__int64 __fastcall msm_eud_resume(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x19
  unsigned int v3; // w0
  __int64 result; // x0
  unsigned int v5; // w21

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_BYTE *)(v1 + 625) != 1 )
    return 0;
  v2 = *(_QWORD *)(v1 + 640);
  if ( !v2 )
    return 0;
  v3 = clk_prepare(*(_QWORD *)(v1 + 640));
  if ( v3 )
  {
    v5 = v3;
    goto LABEL_9;
  }
  result = clk_enable(v2);
  if ( (_DWORD)result )
  {
    v5 = result;
    clk_unprepare(v2);
LABEL_9:
    dev_err(*(_QWORD *)v1, "%s failed to vote ahb2phy clk %d\n", "msm_eud_resume", v5);
    return v5;
  }
  return result;
}
