__int64 __fastcall sbr_link_recovery_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(
                a3,
                4096,
                "PCIe: RC%d: sbr_link_recovery is set to: 0x%x\n",
                *(_DWORD *)(*(_QWORD *)(a1 + 152) + 1348LL),
                *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) + 1341LL));
}
