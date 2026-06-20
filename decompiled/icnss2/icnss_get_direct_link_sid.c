__int64 __fastcall icnss_get_direct_link_sid(__int64 a1, unsigned __int16 *a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  __int64 compatible_node; // x0
  const char *v6; // x19
  int v7; // w2
  __int64 v8; // [xsp+8h] [xbp-58h] BYREF
  int v9; // [xsp+10h] [xbp-50h]
  int v10; // [xsp+14h] [xbp-4Ch]
  __int64 v11; // [xsp+18h] [xbp-48h]
  __int64 v12; // [xsp+20h] [xbp-40h]
  __int64 v13; // [xsp+28h] [xbp-38h]
  __int64 v14; // [xsp+30h] [xbp-30h]
  __int64 v15; // [xsp+38h] [xbp-28h]
  __int64 v16; // [xsp+40h] [xbp-20h]
  __int64 v17; // [xsp+48h] [xbp-18h]
  __int64 v18; // [xsp+50h] [xbp-10h]
  __int64 v19; // [xsp+58h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 152);
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v8 = 0;
  v10 = 0;
  v9 = 1;
  if ( !v2 )
    goto LABEL_2;
  compatible_node = of_find_compatible_node(0, 0, "qcom,icnss-direct-link");
  if ( !compatible_node )
  {
    v6 = "%sicnss2: Unable to get direct link node";
    printk("%sicnss2: Unable to get direct link node", byte_130B32);
LABEL_9:
    ipc_log_string(icnss_ipc_log_context, v6, &unk_12DBF3);
    result = 4294967277LL;
    goto LABEL_3;
  }
  if ( (unsigned int)_of_parse_phandle_with_args(compatible_node, "iommus", "#iommu-cells", 0xFFFFFFFFLL, 0, &v8) )
  {
    v6 = "%sicnss2: Unable to parse iommus property";
    printk("%sicnss2: Unable to parse iommus property", byte_130B32);
    goto LABEL_9;
  }
  v7 = v10 & 0x1F;
  *a2 = v10 & 0x1F;
  printk("%sicnss2: Direct link SID value:%u", byte_13289B, v7);
  ipc_log_string(icnss_ipc_log_context, "%sicnss2: Direct link SID value:%u", (const char *)&unk_12DBF3, *a2);
LABEL_2:
  result = 0;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
