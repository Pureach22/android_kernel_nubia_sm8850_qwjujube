__int64 __fastcall sde_connector_unregister_event(__int64 a1, unsigned int a2)
{
  return sde_connector_register_event(a1, a2, 0, 0);
}
