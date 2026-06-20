bool is_page_owner_enabled()
{
  return md_debug_page_owner_inited && *(_DWORD *)md_debug_page_owner_inited;
}
