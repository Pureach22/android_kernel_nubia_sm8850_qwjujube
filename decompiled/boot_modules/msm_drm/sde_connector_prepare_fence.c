__int64 __fastcall sde_connector_prepare_fence(__int64 result)
{
  if ( !result )
    return printk(&unk_242658, "sde_connector_prepare_fence");
  if ( (*(_BYTE *)(result + 5129) & 1) == 0 )
    return sde_fence_prepare(*(_QWORD *)(result + 2864));
  return result;
}
