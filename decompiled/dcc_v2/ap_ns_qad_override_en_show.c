__int64 __fastcall ap_ns_qad_override_en_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a1 + 152);
  if ( *(_DWORD *)(v3 + 104) == 2 )
    return (int)scnprintf(
                  a3,
                  4096,
                  "%d\n",
                  *(unsigned __int8 *)(*(_QWORD *)(v3 + 376) + *(unsigned __int8 *)(v3 + 332)));
  dev_err(a1, "QAD output is not supported\n");
  return -22;
}
