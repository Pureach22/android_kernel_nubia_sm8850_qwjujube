__int64 __fastcall link_speed_override_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(
                a3,
                4096,
                "PCIe: RC%d: link speed override is set to: 0x%x\n",
                *(_DWORD *)(*(_QWORD *)(a1 + 152) + 1348LL),
                *(_DWORD *)(*(_QWORD *)(a1 + 152) + 1336LL));
}
