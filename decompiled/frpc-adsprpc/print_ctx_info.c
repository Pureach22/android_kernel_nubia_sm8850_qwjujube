__int64 __fastcall print_ctx_info(__int64 a1, __int64 a2)
{
  unsigned __int8 *v3; // x23
  unsigned __int8 *v4; // x24

  v3 = (unsigned __int8 *)(a2 + 64105);
  v4 = (unsigned __int8 *)(a2 + 51668);
  seq_printf(a1, "%s %8s %d\n", "domain_id", ":", *(_DWORD *)a2);
  seq_printf(a1, "%s %8s %d\n", "sesscount", ":", *(_DWORD *)(a2 + 4));
  seq_printf(a1, "%s %10s %d\n", "vmcount", ":", *(_DWORD *)(a2 + 8));
  seq_printf(a1, "%s %12s %llu\n", "perms", ":", *(_QWORD *)(a2 + 16));
  seq_printf(a1, "%s %s %d\n", "valid_attributes", ":", *v4);
  seq_printf(a1, "%s %3s %d\n", "cpuinfo_status", ":", v4[1]);
  seq_printf(a1, "%s %2s %d\n", "staticpd_status", ":", v4[2]);
  seq_printf(a1, "%s %11s %d\n", "secure", ":", *v3);
  return seq_printf(a1, "%s %s %d\n", "unsigned_support", ":", v3[1]);
}
