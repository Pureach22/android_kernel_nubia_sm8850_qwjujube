__int64 __fastcall qcom_map_pil_imem_resource(__int64 a1, __int64 a2)
{
  __int64 compatible_node; // x0
  __int64 result; // x0

  compatible_node = of_find_compatible_node(0, 0, a1);
  if ( compatible_node )
  {
    LODWORD(result) = of_address_to_resource(compatible_node, 0, a2);
    if ( (result & 0x80000000) != 0 )
    {
      return (int)result;
    }
    else
    {
      result = ioremap_prot();
      if ( !result )
      {
        printk(&unk_651D);
        return -12;
      }
    }
  }
  else
  {
    printk(&unk_64D2);
    return -2;
  }
  return result;
}
