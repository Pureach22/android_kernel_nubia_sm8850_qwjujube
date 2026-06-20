__int64 __fastcall _dp_ipa_tx_buf_smmu_mapping(__int64 a1, char a2)
{
  __int64 v2; // x26
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x24
  unsigned int v14; // w23
  unsigned int v15; // w25
  __int64 v16; // x28
  _DWORD *v17; // x1
  __int64 v18; // x28

  v2 = *(unsigned int *)(a1 + 18072);
  if ( (ipa_is_ready() & 1) == 0 )
  {
    qdf_trace_msg(0x45u, 5u, "%s: IPA is not READY", v5, v6, v7, v8, v9, v10, v11, v12, "__dp_ipa_tx_buf_smmu_mapping");
    return 0;
  }
  if ( !(_DWORD)v2 )
    return 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  do
  {
    v17 = *(_DWORD **)(*(_QWORD *)(a1 + 18120) + 8 * v13);
    if ( !v17 )
    {
      v16 = jiffies;
      if ( _dp_ipa_tx_buf_smmu_mapping___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: No nbuf exist at index - %d, create - %d",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "__dp_ipa_tx_buf_smmu_mapping",
          (unsigned int)v13,
          a2 & 1);
        _dp_ipa_tx_buf_smmu_mapping___last_ticks = v16;
      }
      goto LABEL_6;
    }
    v15 = _dp_ipa_handle_buf_smmu_mapping(a1, (__int64)v17, v17[54] + v17[53] - v17[56], a2 & 1);
    if ( v15 )
    {
      v18 = jiffies;
      if ( _dp_ipa_tx_buf_smmu_mapping___last_ticks_91 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: smmu map/unmap failed for index - %d, create - %d",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "__dp_ipa_tx_buf_smmu_mapping",
          (unsigned int)v13,
          a2 & 1);
        _dp_ipa_tx_buf_smmu_mapping___last_ticks_91 = v18;
      }
LABEL_6:
      v14 += (a2 & 1) == 0;
    }
    ++v13;
  }
  while ( v2 != v13 );
  if ( v14 )
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: smmu unmap failed for %d buffers, total tx buffer - %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "__dp_ipa_tx_buf_smmu_mapping",
      v14,
      (unsigned int)(v13 - 1));
  return v15;
}
