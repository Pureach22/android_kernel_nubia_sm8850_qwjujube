__int64 __fastcall cscfg_param_value_show(__int64 a1, __int64 a2)
{
  return (int)scnprintf(
                a2,
                4096,
                "0x%llx\n",
                *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 - 8) + 40LL) + 16LL * *(int *)(a1 - 16) + 8));
}
