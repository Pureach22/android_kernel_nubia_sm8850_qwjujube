__int64 __fastcall sg_allow_access(__int64 a1, __int64 a2)
{
  if ( *(_BYTE *)(**(_QWORD **)(*(_QWORD *)(a1 + 32) + 16LL) + 176LL) == 6 )
    return 0;
  else
    return (unsigned int)(scsi_cmd_allowed(a2, (*(_DWORD *)(a1 + 12) >> 1) & 1) & 1) - 1;
}
