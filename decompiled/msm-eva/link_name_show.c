__int64 __fastcall link_name_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 || *(_QWORD *)(v3 + 248) != a1 )
    return 0;
  strcpy(a3, "msm_cvp\n");
  return 8;
}
