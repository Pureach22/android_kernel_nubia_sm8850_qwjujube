__int64 __fastcall ver_info_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(
                a3,
                40,
                "FW ver=0x%x%x, HW ver=%d.%d.%d\n",
                *(_DWORD *)(*(_QWORD *)(a1 + 152) + 1024LL),
                *(_DWORD *)(*(_QWORD *)(a1 + 152) + 1024LL),
                *(_DWORD *)(*(_QWORD *)(a1 + 152) + 1012LL),
                *(_DWORD *)(*(_QWORD *)(a1 + 152) + 1016LL),
                *(_DWORD *)(*(_QWORD *)(a1 + 152) + 1020LL));
}
