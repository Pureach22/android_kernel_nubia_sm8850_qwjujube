__int64 __fastcall cti_trig_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(
                a3,
                4096,
                "%d\n",
                *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 336LL)
                                   + *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) + 332LL)));
}
