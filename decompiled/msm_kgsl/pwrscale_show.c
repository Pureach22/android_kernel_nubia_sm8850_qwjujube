__int64 __fastcall pwrscale_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x9

  v3 = *(_QWORD *)(a1 + 152);
  v4 = 8660;
  if ( *(_BYTE *)(v3 + 14232) )
    v4 = 11880;
  return (int)scnprintf(a3, 4096, "%u\n", *(unsigned __int8 *)(v3 + v4));
}
