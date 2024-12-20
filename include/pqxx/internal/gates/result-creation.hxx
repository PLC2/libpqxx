#include <pqxx/internal/callgate.hxx>

namespace pqxx::internal::gate
{
class PQXX_PRIVATE result_creation : callgate<result const>
{
  friend class pqxx::connection;
  friend class pqxx::pipeline;

  result_creation(reference x) : super(x) {}

  static result create(
    std::shared_ptr<internal::pq::PGresult> rhs,
    std::shared_ptr<std::string> const &query,
    std::shared_ptr<pqxx::internal::notice_waiters> &notice_waiters,
    encoding_group enc)
  {
    return result(rhs, query, notice_waiters, enc);
  }

  void check_status(std::string_view desc = ""sv) const
  {
    return home().check_status(desc);
  }
};
} // namespace pqxx::internal::gate
