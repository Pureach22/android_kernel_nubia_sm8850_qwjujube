__int64 __fastcall sde_connector_complete_commit(__int64 result, __int64 a2, __int64 a3)
{
  if ( !result )
    return printk(&unk_242658, "sde_connector_complete_commit");
  if ( (*(_BYTE *)(result + 5129) & 1) == 0 )
    return sde_fence_signal(*(_QWORD *)(result + 2864), a2, a3, 0);
  return result;
}
